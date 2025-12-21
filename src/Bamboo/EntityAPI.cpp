#include "Bamboo/EntityAPI.hpp"
#include "Panda/OuterScriptHook.hpp"

namespace Bamboo {

namespace EntityAPI {
    std::string getComponentName(ComponentType type) {
        switch (type) {
            case ComponentType::MESH_COMPONENT:
                return "MeshComponent";
            case ComponentType::RIGIDBODY_2D_COMPONENT:
                return "Rigidbody2DComponent";
            case ComponentType::SPRITE_RENDERER_COMPONENT:
                return "SpriteRendererComponent";
            case ComponentType::TRANSFORM_COMPONENT: {
                return "TransformComponent";
            }
        }
        return "UnknownComponent";
    }

    void createComponent(EntityHandle entity, const std::string &name) {
        Panda::ExternalCalls::entity_CreateComponent(entity.id, name.c_str());
    }

    const char *getName(EntityHandle entity) {
        return Panda::ExternalCalls::entity_GetName(entity.id);
    }

    void addComponent(EntityHandle handle, ComponentType type) {
        createComponent(handle, getComponentName(type));
    }

} // namespace EntityAPI

} // namespace Bamboo