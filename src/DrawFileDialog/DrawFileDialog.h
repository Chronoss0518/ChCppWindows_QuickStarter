#pragma once

class DrawFileDialog : public ApplicationBase
{
public:

	void Init(HINSTANCE)override;

	void Update()override;

	void Release()override;

private:
	CreateApplicationWindow applicationBase;
};