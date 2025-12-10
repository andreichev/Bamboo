#pragma once

#include "Bamboo/Script.hpp"
#include "Bamboo/Logger.hpp"
#include "Bamboo/Assets/Material.hpp"
#include "Panda/Base.hpp"
#include "ScriptClass.hpp"
#include "Bamboo/Allocator.hpp"
#include "Bamboo/Base.hpp"

#include <unordered_map>
#include <cstring>

namespace Panda {

class ScriptRegistry {
private:
    template<typename T>
    static auto addFieldsIfHas(ScriptClass &) -> std::enable_if_t<!hasFields<T>> {}

    template<typename T>
    static auto addFieldsIfHas(ScriptClass &info) -> std::enable_if_t<hasFields<T>> {
        info.fields = StripType<T>::getFields();
    }

    struct ScriptEntry {
        ScriptClassHandle classHandle;
        Bamboo::Shared<Bamboo::Script> script;
    };

    std::vector<ScriptClass> m_scriptClasses;
    std::unordered_map<ScriptInstanceHandle, ScriptEntry> m_instances;

public:
    ~ScriptRegistry() {
        clear();
    }

    std::vector<ScriptClass> getClasses() {
        return m_scriptClasses;
    }

    template<typename T>
    ScriptFieldType getType() {
        if constexpr (std::is_same_v<T, int>) {
            return ScriptFieldType::INTEGER;
        }
        if constexpr (std::is_same_v<T, float>) {
            return ScriptFieldType::FLOAT;
        }
        if constexpr (std::is_same_v<T, Bamboo::Entity>) {
            return ScriptFieldType::ENTITY;
        }
        if constexpr (std::is_same_v<T, Bamboo::Texture>) {
            return ScriptFieldType::TEXTURE;
        }
        if constexpr (std::is_same_v<T, Bamboo::Material>) {
            return ScriptFieldType::MATERIAL;
        }
        return ScriptFieldType::UNKNOWN;
    }

    template<typename FieldType>
    ScriptFieldInfo makeFieldInfo(const char *fieldName, uint32_t offset) {
        ScriptFieldType type = getType<FieldType>();

        using TypeRemovedExtents = std::remove_all_extents_t<FieldType>;
        using TypeRemovedRefs = std::remove_reference_t<TypeRemovedExtents>;
        using TypeRemovedPtrs = RemoveAllPointers<TypeRemovedRefs>;
        constexpr bool isRef = std::is_reference_v<FieldType>;
        constexpr bool isConst = std::is_const_v<TypeRemovedPtrs>;

        static_assert(!isConst, "Const types in script fields not supported");
        static_assert(!isRef, "Reference types in script fields not supported");

        return ScriptFieldInfo(type, fieldName, offset, sizeof(FieldType), alignof(FieldType));
    }

    template<typename T>
    void registerScriptClass(const char *name) {
        ScriptClass clazz;
        clazz.name = name;
        addFieldsIfHas<T>(clazz);
        clazz.instantiateFunc = [](Bamboo::Shared<Bamboo::Entity> entity) {
            Bamboo::Shared<T> script = Bamboo::makeShared<T>();
            script->m_entity = entity;
            return script;
        };
        m_scriptClasses.emplace_back(clazz);
    }

    ScriptEntry getEntryWithId(ScriptInstanceHandle id) {
        if (m_instances.find(id) == m_instances.end()) {
            return {};
        }
        return m_instances.at(id);
    }

    void setFieldValue(ScriptInstanceHandle scriptId, FieldHandle fieldId, void *value) {
        ScriptEntry scriptEntry = getEntryWithId(scriptId);
        // PND_ASSERT(scriptEntry.script, "Invalid script instance id");
        ScriptClassHandle classHandle = scriptEntry.classHandle;
        // PND_ASSERT(classHandle >= 0 && classHandle < m_scriptClasses.size(), "Invalid class
        // handle");
        ScriptClass &clazz = m_scriptClasses[classHandle];
        // PND_ASSERT(clazz.fields.find(fieldId) != clazz.fields.end(), "Invalid field id");
        ScriptFieldInfo &info = clazz.fields.at(fieldId);
        void *fieldPtr = addOffset(scriptEntry.script.get(), info.offset);
        switch (info.type) {
            case ScriptFieldType::INTEGER:
            case ScriptFieldType::FLOAT: {
                memcpy(fieldPtr, value, info.size);
                break;
            }
            case ScriptFieldType::ENTITY: {
                using FieldType = Bamboo::Entity;
                uint32_t *id = (uint32_t *)value;
                FieldType value = FieldType(*id);
                FieldType *field = static_cast<FieldType *>(fieldPtr);
                *field = value;
                break;
            }
            case ScriptFieldType::TEXTURE: {
                using FieldType = Bamboo::Texture;
                uint32_t *id = (uint32_t *)value;
                FieldType value = FieldType(*id);
                FieldType *field = static_cast<FieldType *>(fieldPtr);
                *field = value;
                break;
            }
            case ScriptFieldType::MATERIAL: {
                using FieldType = Bamboo::Material;
                uint32_t *id = (uint32_t *)value;
                FieldType value = FieldType(*id);
                FieldType *field = static_cast<FieldType *>(fieldPtr);
                *field = value;
                break;
            }
            case ScriptFieldType::UNKNOWN: {
                LOG_ERROR("BAMBOO: UNKNOWN FIELD TYPE: %d", info.type);
                break;
            }
        }
    }

    void removeScriptId(ScriptInstanceHandle id) {
        if (m_instances.find(id) == m_instances.end()) {
            return;
        }
        m_instances.erase(id);
    }

    void clear() {
        m_instances.clear();
    }

    ScriptInstanceHandle instantiate(Bamboo::Entity entity, const char *name) {
        for (ScriptClassHandle classId = 0; classId < m_scriptClasses.size(); classId++) {
            ScriptClass &clazz = m_scriptClasses[classId];
            if (Bamboo::strCmp(name, clazz.name) == 0) {
                m_lastHandle++;
                m_instances[m_lastHandle].script = clazz.instantiateFunc(entity);
                m_instances[m_lastHandle].classHandle = classId;
                return m_lastHandle;
            }
        }
        return 0;
    }

private:
    ScriptClassHandle m_lastHandle = 0;
};

ScriptRegistry *getScriptRegistry();

} // namespace Panda
