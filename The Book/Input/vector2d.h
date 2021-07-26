// vector2d.h, Freddie Cooke
// describing the vector object which game objects use as their position

#include <math.h>

class Vector2D {

	public:
		Vector2D(float x, float y) : x_(x), y_(y) {}

		// Accessors
		float x() { return x_; }
		float y() { return y_; }
		float length() { return sqrt(x_ * x_ + y_ * y_); }
		
		// Mutators
		void setX(float x) { x_ = x; }
		void setY(float y) { y_ = y; }
	
		// Operators
		Vector2D operator+(const Vector2D& v2) const {
			return Vector2D(x_ + v2.x_, y_ + v2.y_);
		}

		friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2) {
			v1.x_ += v2.x_;
			v1.y_ += v2.y_;
			return v1;
		}

		Vector2D operator*(const float scalar) {
			return Vector2D(x_ * scalar, y_ * scalar);
		}

		Vector2D& operator*=(const float scalar) {
			x_ *= scalar;
			y_ *= scalar;
			return *this;
		}

		Vector2D operator-(const Vector2D& v2) const {
			return Vector2D(x_ - v2.x_, y_ - v2.y_);
		}

		friend Vector2D& operator-=(Vector2D& v1, const Vector2D v2) {
			v1.x_ -= v2.x_;
			v1.y_ -= v2.y_;
			return v1;
		}

		Vector2D operator/(float scalar) const {
			return Vector2D(x_ / scalar, y_ / scalar);
		}

		Vector2D operator/=(float scalar) {
			x_ /= scalar;
			y_ /= scalar;
			return *this;
		}

		void normalise() { // Unit vector
			float l = length();
			if (l > 0) {
				(*this) *= 1 / l;
			}
		}

	private:
		float x_, y_;
};
