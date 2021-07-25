// loaderparams.h, Freddie Cooke
// this class allows objects to be loaded with different arguments.
// this class assigns passed paramaters to an objects properties.

#pragma once

#include <string>

using namespace std;

class LoaderParams {

	public:
		LoaderParams(int x, int y, int w, int h, std::string textureID) : x_(x), y_(y), w_(w), h_(h), textureID_(textureID) {  
			//
		}

		// Accessors
		int x() const { return x_; }
		int y() const { return y_; }
		int w() const { return w_; }
		int h() const { return h_; }
		string textureID() const { return textureID_; }

	private:
		int x_, y_;
		int w_, h_;
		string textureID_;
};
