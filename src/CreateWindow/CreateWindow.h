#pragma once

class CreateApplicationWindow : public ApplicationBase
{
public:

	void Init(HINSTANCE _hIns)override;

	void Init(HINSTANCE _hIns, const std::string& _appName);

	void Update()override;

	bool IsUpdate();

	void Release()override;

public:

	ChWin::WindObject& GetWindObject() { return windObject; }

private:

	ChWin::WindObject windObject;
	ChWin::WindClassObject classObject;

};