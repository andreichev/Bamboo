//
// Created by Michael Andreichev on 02.08.2024.
//

#include "Panda/OuterScriptHook.hpp"
#include "Panda/ScriptClassMaper.hpp"
#include "Bamboo/ScriptRegistry/ScriptRegistry.hpp"
#include "Bamboo/Script.hpp"

#include <iostream>

namespace Panda {

namespace ExternalCalls {
    /// APPLICATION
    Application_Quit application_Quit = nullptr;
    Application_GetWidth application_GetWidth = nullptr;
    Application_GetHeight application_GetHeight = nullptr;
    /// WORLD
    World_Load world_Load = nullptr;
    World_FindByTag world_FindByTag = nullptr;
    World_CreateEntity world_CreateEntity = nullptr;
    World_DestroyEntity world_DestroyEntity = nullptr;
    /// INPUT
    Input_IsKeyPressed input_IsKeyPressed = nullptr;
    Input_IsKeyJustPressed input_IsKeyJustPressed = nullptr;
    /// ENTITY
    Entity_CreateComponent entity_CreateComponent = nullptr;
    Entity_HasComponent entity_HasComponent = nullptr;
    Entity_RemoveComponent entity_RemoveComponent = nullptr;
    Entity_GetName entity_GetName = nullptr;
    /// TRANSFORM COMPONENT
    TransformComponent_GetPosition transformComponent_GetPosition = nullptr;
    TransformComponent_SetPosition transformComponent_SetPosition = nullptr;
    TransformComponent_GetRotationEuler transformComponent_GetRotationEuler = nullptr;
    TransformComponent_SetRotationEuler transformComponent_SetRotationEuler = nullptr;
    TransformComponent_GetScale transformComponent_GetScale = nullptr;
    TransformComponent_SetScale transformComponent_SetScale = nullptr;
    /// SPRITE RENDERER COMPONENT
    SpriteRendererComponent_GetColor spriteRendererComponent_GetColor = nullptr;
    SpriteRendererComponent_SetColor spriteRendererComponent_SetColor = nullptr;
    SpriteRendererComponent_GetMaterial spriteRendererComponent_GetMaterial = nullptr;
    SpriteRendererComponent_SetMaterial spriteRendererComponent_SetMaterial = nullptr;
    SpriteRendererComponent_SetCell spriteRendererComponent_SetCell = nullptr;
    /// MESH COMPONENT
    MeshComponent_GetMesh meshComponent_GetMesh = nullptr;
    MeshComponent_SetMesh meshComponent_SetMesh = nullptr;
    /// RIGIDBODY2D COMPONENT
    Rigidbody2DComponent_ApplyForce rigidbody2DComponent_ApplyForce = nullptr;
    Rigidbody2DComponent_ApplyLinearImpulse rigidbody2DComponent_ApplyLinearImpulse = nullptr;
    Rigidbody2DComponent_GetLinearVelocity rigidbody2DComponent_GetLinearVelocity = nullptr;
    Rigidbody2DComponent_SetLinearVelocity rigidbody2DComponent_SetLinearVelocity = nullptr;
    Rigidbody2DComponent_GetMass rigidbody2DComponent_GetMass = nullptr;
    Rigidbody2DComponent_GetFriction rigidbody2DComponent_GetFriction = nullptr;
    Rigidbody2DComponent_SetFriction rigidbody2DComponent_SetFriction = nullptr;
    /// MATERIAL
    Material_SetFloatValue material_SetFloatValue = nullptr;
    Material_SetVec4Value material_SetVec4Value = nullptr;
    Material_SetTextureValue material_SetTextureValue = nullptr;
    /// MESH
    Mesh_Create mesh_Create = nullptr;
    Mesh_Update mesh_Update = nullptr;
    Mesh_SetMaterial mesh_SetMaterial = nullptr;
    Mesh_Delete mesh_Delete = nullptr;
    /// CONSOLE
    Console_Log console_Log = nullptr;
} // namespace ExternalCalls

namespace InternalCalls {
    void clear() {
        Bamboo::getScriptRegistry()->clear();
    }

    Handle instantiateScript(Handle entityHandle, const char *name) {
        Bamboo::Entity entity = Bamboo::Entity(entityHandle);
        return Bamboo::getScriptRegistry()->instantiate(entity, name);
    }

    void invokeUpdateAtScript(Handle handle, float deltaTime) {
        Bamboo::Shared<Bamboo::Script> script =
            Bamboo::getScriptRegistry()->getEntryWithId(handle).script;
        if (!script) {
            // assert(false);
            return;
        }
        script->update(deltaTime);
    }

    void invokeStartAtScript(Handle handle) {
        Bamboo::Shared<Bamboo::Script> script =
            Bamboo::getScriptRegistry()->getEntryWithId(handle).script;
        if (!script) {
            // assert(false);
            return;
        }
        script->start();
    }

    void invokeBeginCollisionTouch(Handle handle, Handle entityHandle) {
        Bamboo::Shared<Bamboo::Script> script =
            Bamboo::getScriptRegistry()->getEntryWithId(handle).script;
        if (!script) {
            // assert(false);
            return;
        }
        script->beginCollisionTouch(Bamboo::Entity(entityHandle));
    }

    void invokeEndCollisionTouch(Handle handle, Handle entityHandle) {
        Bamboo::Shared<Bamboo::Script> script =
            Bamboo::getScriptRegistry()->getEntryWithId(handle).script;
        if (!script) {
            // assert(false);
            return;
        }
        script->endCollisionTouch(Bamboo::Entity(entityHandle));
    }

    void invokeBeginSensorOverlap(Handle handle, Handle entityHandle) {
        Bamboo::Shared<Bamboo::Script> script =
            Bamboo::getScriptRegistry()->getEntryWithId(handle).script;
        if (!script) {
            // assert(false);
            return;
        }
        script->beginSensorOverlap(Bamboo::Entity(entityHandle));
    }

    void invokeEndSensorOverlap(Handle handle, Handle entityHandle) {
        Bamboo::Shared<Bamboo::Script> script =
            Bamboo::getScriptRegistry()->getEntryWithId(handle).script;
        if (!script) {
            // assert(false);
            return;
        }
        script->endSensorOverlap(Bamboo::Entity(entityHandle));
    }

    void setFieldValue(Handle scriptId, FieldHandle fieldId, void *value) {
        Bamboo::getScriptRegistry()->setFieldValue(scriptId, fieldId, value);
    }

    ScriptBundleManifest getManifest() {
        return ScriptClassMapper::getClassesManifest(Bamboo::getScriptRegistry()->getClasses());
    }
} // namespace InternalCalls

std::unordered_map<std::string, void *> g_scriptSymbols;

void initScriptHook() {
    using namespace InternalCalls;
    g_scriptSymbols["clear"] = (void *)clear;
    g_scriptSymbols["instantiateScript"] = (void *)instantiateScript;
    g_scriptSymbols["setFieldValue"] = (void *)setFieldValue;
    g_scriptSymbols["invokeStartAtScript"] = (void *)invokeStartAtScript;
    g_scriptSymbols["invokeUpdateAtScript"] = (void *)invokeUpdateAtScript;
    g_scriptSymbols["invokeBeginCollisionTouch"] = (void *)invokeBeginCollisionTouch;
    g_scriptSymbols["invokeEndCollisionTouch"] = (void *)invokeEndCollisionTouch;
    g_scriptSymbols["invokeBeginSensorOverlap"] = (void *)invokeBeginSensorOverlap;
    g_scriptSymbols["invokeEndSensorOverlap"] = (void *)invokeEndSensorOverlap;
    g_scriptSymbols["getManifest"] = (void *)getManifest;
}

//////////////////////////////////////////////////////////////////
///---------------------Functions binding----------------------///
//////////////////////////////////////////////////////////////////

#if defined(_WIN32) || defined(_WIN64)
#    define LIB_EXPORT __declspec(dllexport)
#else
#    define LIB_EXPORT
#endif

extern "C" {

using SymbolsLoadFunc = void *(*)(const char *name);

LIB_EXPORT int loadExternalCalls(SymbolsLoadFunc load) {
    using namespace ExternalCalls;
    /// APPLICATION
    application_Quit = (Application_Quit)load("application_Quit");
    application_GetWidth = (Application_GetWidth)load("application_GetWidth");
    application_GetHeight = (Application_GetHeight)load("application_GetHeight");
    /// WORLD
    world_Load = (World_Load)load("world_Load");
    world_FindByTag = (World_FindByTag)load("world_FindByTag");
    world_CreateEntity = (World_CreateEntity)load("world_CreateEntity");
    world_DestroyEntity = (World_DestroyEntity)load("world_DestroyEntity");
    entity_GetName = (Entity_GetName)load("entity_GetName");
    /// INPUT
    input_IsKeyPressed = (Input_IsKeyPressed)load("input_IsKeyPressed");
    input_IsKeyJustPressed = (Input_IsKeyJustPressed)load("input_IsKeyJustPressed");
    /// ENTITY
    entity_CreateComponent = (Entity_CreateComponent)load("entity_CreateComponent");
    entity_HasComponent = (Entity_HasComponent)load("entity_HasComponent");
    entity_RemoveComponent = (Entity_RemoveComponent)load("entity_RemoveComponent");
    /// TRANSFORM COMPONENT
    transformComponent_GetPosition =
        (TransformComponent_GetPosition)load("transformComponent_GetPosition");
    transformComponent_SetPosition =
        (TransformComponent_SetPosition)load("transformComponent_SetPosition");
    transformComponent_GetRotationEuler =
        (TransformComponent_GetRotationEuler)load("transformComponent_GetRotationEuler");
    transformComponent_SetRotationEuler =
        (TransformComponent_SetRotationEuler)load("transformComponent_SetRotationEuler");
    transformComponent_GetScale = (TransformComponent_GetScale)load("transformComponent_GetScale");
    transformComponent_SetScale = (TransformComponent_SetScale)load("transformComponent_SetScale");
    /// SPRITE RENDERER COMPONENT
    spriteRendererComponent_GetColor =
        (SpriteRendererComponent_GetColor)load("spriteRendererComponent_GetColor");
    spriteRendererComponent_SetColor =
        (SpriteRendererComponent_SetColor)load("spriteRendererComponent_SetColor");
    spriteRendererComponent_GetMaterial =
        (SpriteRendererComponent_GetMaterial)load("spriteRendererComponent_GetMaterial");
    spriteRendererComponent_SetMaterial =
        (SpriteRendererComponent_SetMaterial)load("spriteRendererComponent_SetMaterial");
    spriteRendererComponent_SetCell =
        (SpriteRendererComponent_SetCell)load("spriteRendererComponent_SetCell");
    /// MESH COMPONENT
    meshComponent_GetMesh = (MeshComponent_GetMesh)load("meshComponent_GetMesh");
    meshComponent_SetMesh = (MeshComponent_SetMesh)load("meshComponent_SetMesh");
    /// RIGIDBODY2D COMPONENT
    rigidbody2DComponent_ApplyForce =
        (Rigidbody2DComponent_ApplyForce)load("rigidbody2DComponent_ApplyForce");
    rigidbody2DComponent_ApplyLinearImpulse =
        (Rigidbody2DComponent_ApplyLinearImpulse)load("rigidbody2DComponent_ApplyLinearImpulse");
    rigidbody2DComponent_GetLinearVelocity =
        (Rigidbody2DComponent_GetLinearVelocity)load("rigidbody2DComponent_GetLinearVelocity");
    rigidbody2DComponent_SetLinearVelocity =
        (Rigidbody2DComponent_SetLinearVelocity)load("rigidbody2DComponent_SetLinearVelocity");
    rigidbody2DComponent_GetMass =
        (Rigidbody2DComponent_GetMass)load("rigidbody2DComponent_GetMass");
    rigidbody2DComponent_GetFriction =
        (Rigidbody2DComponent_GetFriction)load("rigidbody2DComponent_GetFriction");
    rigidbody2DComponent_SetFriction =
        (Rigidbody2DComponent_SetFriction)load("rigidbody2DComponent_SetFriction");
    /// MATERIAL
    material_SetFloatValue = (Material_SetFloatValue)load("material_SetFloatValue");
    material_SetVec4Value = (Material_SetVec4Value)load("material_SetVec4Value");
    material_SetTextureValue = (Material_SetTextureValue)load("material_SetTextureValue");
    /// MESH
    mesh_Create = (Mesh_Create)load("mesh_Create");
    mesh_Update = (Mesh_Update)load("mesh_Update");
    mesh_SetMaterial = (Mesh_SetMaterial)load("mesh_SetMaterial");
    mesh_Delete = (Mesh_Delete)load("mesh_Delete");
    /// LOG
    console_Log = (Console_Log)load("console_Log");
    std::cout << "SCRIPT ENGINE: Outer functions binding done.\n";
    return 0;
}

LIB_EXPORT void *loadInternalCall(const char *name) {
    if (g_scriptSymbols.empty()) {
        initScriptHook();
    }
    if (g_scriptSymbols.find(name) == g_scriptSymbols.end()) {
        std::cerr << "SCRIPT ENGINE ERROR: Outer function not found: " << name << "\n";
        return nullptr;
    }
    return g_scriptSymbols.at(name);
}

LIB_EXPORT void hookFunc() {
    loadExternalCalls(nullptr);
    loadInternalCall(nullptr);
}
}

} // namespace Panda