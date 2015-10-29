#ifndef _AVERAGINGCONTROLLER_H_
#define _AVERAGINGCONTROLLER_H_

#include "ViewportManager.h"
#include "ViewportHost.h"

class Curve;

class AveragingController : public IAppController
{
public:
  void init() override;

  AveragingController(ViewportManager& viewportManager);
  int onMousePressed(int mouseX, int mouseY, const IKeyboardState& keyboardState) override;
  int onMouseReleased(int mouseX, int mouseY, const IKeyboardState& keyboardState) override;
  int onMouseDragged(int deltaX, int deltaY, const IKeyboardState& keyboardState) override;
  int onMouseMoved(int deltaX, int deltaY, const IKeyboardState& keyboardState) override;
  int onClick(int mouseX, int mouseY, const IKeyboardState& keyboardState) override;
  int onKeyReleased(int ch) override;
  int onKeyPressed(int ch) override;

  int onCommand(const std::string& command) override;
  void onIdle() override;

  void onNotify(int message) override;

private:
  ViewportManager& m_viewportManager;
  Curve* m_pCurve;
};

#endif//_AVERAGINGCONTROLLER_H_