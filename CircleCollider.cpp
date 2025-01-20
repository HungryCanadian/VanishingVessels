#include "CircleCollider.h"

namespace SDLFramework {
	CircleCollider::CircleCollider(float radius, bool broadPhase) : Collider(ColliderType::Circle) {
		mRadius = radius;

		if (DEBUG_COLLIDERS == true) {
			if (broadPhase == true) {
				SetDebugTexture(new SDLTexture("BroadPhaseCollider.png"));
			}
			else {
				SetDebugTexture(new SDLTexture("CircleCollider.png"));
			}
			mDebugTexture->Scale(Vec2_One * (radius * 2 / 50.0f));
		}
	}

	CircleCollider::~CircleCollider() {

	}

	Vector2 CircleCollider::GetFurthestPoint() {
		return Vec2_Right * (mRadius + getPosition(GameEntity::Local).Magnitude());
	}

	float CircleCollider::getRadius() {
		return mRadius;
	}


}
