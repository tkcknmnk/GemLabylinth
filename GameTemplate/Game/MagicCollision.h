#pragma once

class Player;

class MagicCollision : public IGameObject
{
public:
	MagicCollision();
	~MagicCollision();
	bool Start();
	void Move();
	void Update();
	//座標を設定
	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}
	//回転を設定
	void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
	}

private:
	Vector3 m_position;
	Vector3 m_moveSpeed;
	Quaternion m_rotation;
	float m_timer = 0.0f;
	CollisionObject* m_collisionObject = nullptr;   
	Player* m_player = nullptr;
};

