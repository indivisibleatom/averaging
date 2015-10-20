#include "precomp.h"
#include "averagingController.h"
#include "plane.h"

AveragingController::AveragingController(ViewportManager& viewportManager) : m_viewportManager(viewportManager)
{
  std::unique_ptr< Viewport > pView1(new Viewport(m_viewportManager.getViewportRect(), *this));
  //pView1->addSceneNode(std::unique_ptr<GeometryNode>(new GeometryNode(std::unique_ptr<Plane>(new Plane(0, 0, 1, 0)))));
  pView1->addSceneNode(std::unique_ptr<GeometryNode>(new GeometryNode(std::unique_ptr<Plane>(new Plane(0, 1, 0, 0)))));
  std::unique_ptr<CameraNode> pCameraNode(new CameraNode()); 
  pView1->setCameraNode(pCameraNode.get());
  ISceneNode* pCamNode = pView1->addSceneNode(std::move(pCameraNode));
  m_viewportManager.addViewport(std::move(pView1));
}

void AveragingController::init() 
{
}

int AveragingController::onMousePressed(int mouseX, int mouseY, const IKeyboardState& keyboardState) 
{
  return 0; 
}

int AveragingController::onMouseReleased(int mouseX, int mouseY, const IKeyboardState& keyboardState)
{
  return 0;
}
int AveragingController::onMouseDragged(int deltaX, int deltaY, const IKeyboardState& keyboardState)
{
  return 0;
}
int AveragingController::onMouseMoved(int deltaX, int deltaY, const IKeyboardState& keyboardState)
{
  return 0;
}

int AveragingController::onClick(int mouseX, int mouseY, const IKeyboardState& keyboardState)
{
  return 0;
}

int AveragingController::onKeyReleased(int ch)
{
  return 0;
}

int AveragingController::onKeyPressed(int ch)
{
  return 0;
}

int AveragingController::onCommand(const std::string& command)
{
  return 0;
}

void AveragingController::onNotify(int message)
{
}
