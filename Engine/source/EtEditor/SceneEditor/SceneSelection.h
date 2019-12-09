#pragma once
#include <vector>

#include <EtFramework/SceneGraph/SceneEvents.h>

#include <EtEditor/Util/EditorTickOrder.h>
#include <EtEditor/Rendering/EntityIdRenderer.h>


class AbstractScene;
class Entity;
class OutlineExtension;


//-------------------------------
// I_SceneSelectionListener
//
// interface for a class that listens for changes in the scene selection
//
class I_SceneSelectionListener
{
public:
	virtual ~I_SceneSelectionListener() = default;

	virtual void OnSceneEvent(E_SceneEvent const, SceneEventData const* const) = 0;
	virtual void OnEntitySelectionChanged(Entity* const entity, bool const selected) = 0;
	virtual void OnEntitySelectionCleared() = 0;
};


//--------------------
// SceneSelection
//
class SceneSelection final 
{
public:

	// ctor dtor
	//---------------
	SceneSelection() = default;
	~SceneSelection() = default;

	// accessors
	//--------------------
	AbstractScene* GetScene() { return m_Scene; }
	std::vector<Entity*> const& GetSelectedEntities() const { return m_SelectedEntities; }

	// functionality
	//--------------------
	void SetScene(AbstractScene* const scene);

	void RegisterListener(I_SceneSelectionListener* const listener);
	void UnregisterListener(I_SceneSelectionListener const* const listener);

	void ClearSelection(bool const notify = false);
	void ToggleEntitySelected(Entity* const entity, bool const notify = false);

	void Pick(ivec2 const pos, Viewport* const viewport, bool const add);

	void UpdateOutlines() const;
	void RecursiveAddOutlines(Entity* const entity) const;

private:
	void OnSceneEvent(T_SceneEventFlags const flags, SceneEventData const* const eventData);
	
	// Data
	///////

	AbstractScene* m_Scene = nullptr;
	std::vector<Entity*> m_SelectedEntities;

	std::vector<I_SceneSelectionListener*> m_Listeners;

	vec4 m_OutlineColor = vec4(0.5f, 0.5f, 1.f, 1.f);

	EntityIdRenderer m_IdRenderer;
	bool m_IsIdRendererInitialized = false;

	OutlineExtension* m_OutlineExtension = nullptr;
};
