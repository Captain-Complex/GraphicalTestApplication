#pragma once
//just followed tutorial
//turns out i didn't need it for matrix hierachry 
#include <vector>
#include <cassert>
struct SceneObject {
public:
	SceneObject() {}
	virtual ~SceneObject() 
	{
		if (m_parent != nullptr)
		{
			m_parent->removeChild(this);
		}

		for (auto child : m_children)
		{
			child->m_parent = nullptr;
		}
	}

	SceneObject* getParent() const
	{
		return m_parent;
	}

	size_t childCount() const
	{
		return m_children.size();
	}

	SceneObject* getChild(unsigned int index) const
	{
		return m_children[index];
	}

	void addChild(SceneObject* child)
	{
		assert(child->m_parent == nullptr);
		child->m_parent = this;
		m_children.push_back(child);
	}

	void removeChild(SceneObject* child)
	{
		auto iter = std::find(m_children.begin(), m_children.end(), child);

		if (iter != m_children.end())
		{
			m_children.erase(iter);
			child->m_parent = nullptr;
		}
	}

	virtual void onUpdate(float deltaTime) {}
	virtual void onDraw() {}

	void update(float deltaTime)
	{
		onUpdate(deltaTime);

		for (auto& child : m_children)
		{
			child->update(deltaTime);
		}
	}

	void draw()
	{
		onDraw();

		for (auto& child : m_children)
		{
			child->draw();
		}
	}

	const Matrix& getLocalTransform() const
	{
		return m_localTransform;
	}
	const Matrix& getGlobalTransform() const 
	{
		return m_globalTranform;
	}

	void updateTransform()
	{
		if (m_parent != nullptr)
		{
			m_globalTranform = m_parent->m_globalTranform * m_localTransform;
		}
		else
		{
			m_globalTranform = m_localTransform;
		}

		for (auto child : m_children)
		{
			child->updateTransform();
		}
	}

	void translate(float x, float y) {
		m_localTransform = MatrixTranslate(x, y, 0);
		updateTransform();
	}

	void rotate(float radians) {
		m_localTransform = MatrixRotateZ(radians);
		updateTransform();
	}

	void scale(float width, float height) {
		m_localTransform = MatrixScale(width, height, 1);
		updateTransform();
	}

protected:

	SceneObject* m_parent = nullptr;
	std::vector<SceneObject*> m_children;

	Matrix m_localTransform = MatrixIdentity();
	Matrix m_globalTranform = MatrixIdentity();
};