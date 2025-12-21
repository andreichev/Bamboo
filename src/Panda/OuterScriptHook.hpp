#pragma once

#include <cstdint>

namespace Panda {

using Handle = uint32_t;

namespace ExternalCalls {

    /// APPLICATION
    using Application_Quit = void (*)();
    extern Application_Quit application_Quit;
    using Application_GetWidth = uint32_t (*)();
    extern Application_GetWidth application_GetWidth;
    using Application_GetHeight = uint32_t (*)();
    extern Application_GetHeight application_GetHeight;
    using Application_IsCursorLocked = bool (*)();
    extern Application_IsCursorLocked application_IsCursorLocked;
    using Application_ToggleCursorLock = void (*)();
    extern Application_ToggleCursorLock application_ToggleCursorLock;
    /// WORLD
    using World_Load = void (*)(const char *name);
    extern World_Load world_Load;
    using World_FindByTag = Handle (*)(const char *tag);
    extern World_FindByTag world_FindByTag;
    using World_CreateEntity = Handle (*)(const char *tag);
    extern World_CreateEntity world_CreateEntity;
    using World_DestroyEntity = void (*)(Handle id);
    extern World_DestroyEntity world_DestroyEntity;
    /// INPUT
    using Input_IsKeyPressed = bool (*)(int key);
    extern Input_IsKeyPressed input_IsKeyPressed;
    using Input_IsKeyJustPressed = bool (*)(int key);
    extern Input_IsKeyJustPressed input_IsKeyJustPressed;
    using Input_IsMouseButtonPressed = bool (*)(int key);
    extern Input_IsMouseButtonPressed input_IsMouseButtonPressed;
    using Input_IsMouseButtonJustPressed = bool (*)(int key);
    extern Input_IsMouseButtonJustPressed input_IsMouseButtonJustPressed;
    using Input_GetMouseDeltaX = double (*)();
    extern Input_GetMouseDeltaX input_GetMouseDeltaX;
    using Input_GetMouseDeltaY = double (*)();
    extern Input_GetMouseDeltaY input_GetMouseDeltaY;
    /// ENTITY
    using Entity_CreateComponent = void (*)(Handle entityHandle, const char *type);
    extern Entity_CreateComponent entity_CreateComponent;
    using Entity_HasComponent = bool (*)(Handle entityHandle, const char *type);
    extern Entity_HasComponent entity_HasComponent;
    using Entity_RemoveComponent = void (*)(Handle entityHandle, const char *type);
    extern Entity_RemoveComponent entity_RemoveComponent;
    using Entity_GetName = const char *(*)(Handle entityHandle);
    extern Entity_GetName entity_GetName;
    /// TRANSFORM COMPONENT
    using TransformComponent_GetPosition =
        void (*)(Handle entityHandle, float *x, float *y, float *z);
    extern TransformComponent_GetPosition transformComponent_GetPosition;
    using TransformComponent_SetPosition = void (*)(Handle entityHandle, float x, float y, float z);
    extern TransformComponent_SetPosition transformComponent_SetPosition;
    using TransformComponent_Translate = void (*)(Handle entityHandle, float x, float y, float z);
    extern TransformComponent_Translate transformComponent_Translate;
    using TransformComponent_GetRotationEuler =
        void (*)(Handle entityHandle, float *x, float *y, float *z);
    extern TransformComponent_GetRotationEuler transformComponent_GetRotationEuler;
    using TransformComponent_SetRotationEuler =
        void (*)(Handle entityHandle, float x, float y, float z);
    extern TransformComponent_SetRotationEuler transformComponent_SetRotationEuler;
    using TransformComponent_GetRotation =
        void (*)(Handle entityHandle, float *w, float *x, float *y, float *z);
    extern TransformComponent_GetRotation transformComponent_GetRotation;
    using TransformComponent_SetRotation =
        void (*)(Handle entityHandle, float w, float x, float y, float z);
    extern TransformComponent_SetRotation transformComponent_SetRotation;
    using TransformComponent_RotateEuler = void (*)(Handle entityHandle, float x, float y, float z);
    extern TransformComponent_RotateEuler transformComponent_RotateEuler;
    using TransformComponent_GetScale = void (*)(Handle entityHandle, float *x, float *y, float *z);
    extern TransformComponent_GetScale transformComponent_GetScale;
    using TransformComponent_SetScale = void (*)(Handle entityHandle, float x, float y, float z);
    extern TransformComponent_SetScale transformComponent_SetScale;
    /// SPRITE RENDERER COMPONENT
    using SpriteRendererComponent_GetColor =
        void (*)(Handle entityHandle, float *r, float *g, float *b, float *a);
    extern SpriteRendererComponent_GetColor spriteRendererComponent_GetColor;
    using SpriteRendererComponent_SetColor =
        void (*)(Handle entityHandle, float r, float g, float b, float a);
    extern SpriteRendererComponent_SetColor spriteRendererComponent_SetColor;
    using SpriteRendererComponent_GetMaterial =
        void (*)(Handle entityHandle, Handle *materialHandle);
    extern SpriteRendererComponent_GetMaterial spriteRendererComponent_GetMaterial;
    using SpriteRendererComponent_SetMaterial =
        void (*)(Handle entityHandle, Handle materialHandle);
    extern SpriteRendererComponent_SetMaterial spriteRendererComponent_SetMaterial;
    using SpriteRendererComponent_SetCell =
        void (*)(Handle entityHandle, int cols, int rows, int index);
    extern SpriteRendererComponent_SetCell spriteRendererComponent_SetCell;
    /// MESH COMPONENT
    using MeshComponent_GetMesh = void (*)(Handle entityHandle, Handle *meshHandle);
    extern MeshComponent_GetMesh meshComponent_GetMesh;
    using MeshComponent_SetMesh = void (*)(Handle entityHandle, Handle meshHandle);
    extern MeshComponent_SetMesh meshComponent_SetMesh;
    /// RIGIDBODY2D COMPONENT
    using Rigidbody2DComponent_ApplyForce = void (*)(Handle entityHandle, float x, float y);
    extern Rigidbody2DComponent_ApplyForce rigidbody2DComponent_ApplyForce;
    using Rigidbody2DComponent_ApplyLinearImpulse = void (*)(Handle entityHandle, float x, float y);
    extern Rigidbody2DComponent_ApplyLinearImpulse rigidbody2DComponent_ApplyLinearImpulse;
    using Rigidbody2DComponent_GetLinearVelocity =
        void (*)(Handle entityHandle, float *x, float *y);
    extern Rigidbody2DComponent_GetLinearVelocity rigidbody2DComponent_GetLinearVelocity;
    using Rigidbody2DComponent_SetLinearVelocity = void (*)(Handle entityHandle, float x, float y);
    extern Rigidbody2DComponent_SetLinearVelocity rigidbody2DComponent_SetLinearVelocity;
    using Rigidbody2DComponent_GetMass = void (*)(Handle entityHandle, float *mass);
    extern Rigidbody2DComponent_GetMass rigidbody2DComponent_GetMass;
    using Rigidbody2DComponent_GetFriction = void (*)(Handle entityHandle, float *friction);
    extern Rigidbody2DComponent_GetFriction rigidbody2DComponent_GetFriction;
    using Rigidbody2DComponent_SetFriction = void (*)(Handle entityHandle, float friction);
    extern Rigidbody2DComponent_SetFriction rigidbody2DComponent_SetFriction;
    /// MATERIAL
    using Material_SetFloatValue = void (*)(Handle materialHandle, const char *name, float value);
    extern Material_SetFloatValue material_SetFloatValue;
    using Material_SetVec4Value =
        void (*)(Handle materialHandle, const char *name, float r, float g, float b, float a);
    extern Material_SetVec4Value material_SetVec4Value;
    using Material_SetTextureValue =
        void (*)(Handle materialHandle, const char *name, Handle textureHandle);
    extern Material_SetTextureValue material_SetTextureValue;
    /// MESH
    using Mesh_Create = void (*)(Handle *handle);
    extern Mesh_Create mesh_Create;
    using Mesh_Update = void (*)(
        Handle handle,
        const void *vertices,
        uint32_t verticesCount,
        const void *indices,
        uint32_t indicesCount
    );
    extern Mesh_Update mesh_Update;
    using Mesh_SetMaterial = void (*)(Handle meshHandle, Handle materialHandle);
    extern Mesh_SetMaterial mesh_SetMaterial;
    using Mesh_Delete = void (*)(Handle meshHandle);
    extern Mesh_Delete mesh_Delete;
    /// LOG
    using Console_Log = void (*)(int type, const char *);
    extern Console_Log console_Log;

} // namespace ExternalCalls

}; // namespace Panda
