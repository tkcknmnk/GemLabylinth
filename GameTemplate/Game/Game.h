#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class BackGround;
class GameCamera;
class ItemDash;
class ItemHeart;
class ItemMagic;
class Enemy;
class Gem;

class Game : public IGameObject
{
public:
	//ステート
	enum EnGameState {
		enGameState_Start,					//スタート
		enGameState_tuto,					//説明
		enGameState_Game,					//ゲーム中
		enGameState_End,					//終わり
		enGameState_Score,					//スコア
	};

public:
	Game() {}
	~Game() {}
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void SpawnItem();
	void SpawnEnemy();

	const EnGameState Get() {
		return m_gameState;
	}

	const Vector3 GetPosition()const
	{
		return playerPos;
	}

private:
	EnGameState m_gameState = enGameState_Game;
	SkyCube m_skyCube;
	PointLight* m_light;
	LevelRender m_levelRender;
	BackGround* m_backGround = nullptr;			//ステージ
	Player* m_player = nullptr;					//プレイヤー
	GameCamera* m_gameCamera = nullptr;			//カメラ
	ItemDash* m_dash = nullptr;
	ItemHeart* m_heart = nullptr;
	ItemMagic* m_magic = nullptr;
	Enemy* m_enemy = nullptr;
	Gem* m_gem = nullptr;

	int itemNum = 0;

	ModelRender m_modelRender;
	Vector3 playerPos;
};//来たわよ

//お願いします！