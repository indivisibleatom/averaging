#include "precomp.h"
#include "averagingController.h"
#include "plane.h"
#include "curve.h"

AveragingController::AveragingController(ViewportManager& viewportManager) : m_viewportManager(viewportManager)
{
  std::unique_ptr< Viewport > pView1(new Viewport(m_viewportManager.getViewportRect(), *this));

  /*boost::filesystem::path planeDataPath("C:/Development/openSource/averaging/averaging/data/planesTest1.dat"); 
  boost::iostreams::mapped_file_source file(planeDataPath);
  const char *currentPtr = file.data();
  char *end = '\0';

  Vector<float> readNormal;
  float readDistance;

  int numPlanes = strtoT<float>(currentPtr, &end);
  int currentPlaneNum = 0;
  currentPtr = end + 1;

  while (errno == 0 && currentPlaneNum++ < numPlanes)
  {
    for (int i = 0; i < 3; i++)
    {
      readNormal.set(i, strtoT<float>(currentPtr, &end));
      currentPtr = end + 1;
    }
    readDistance = strtoT<float>(currentPtr, &end);
    currentPtr = end + 1;
    pView1->addSceneNode(std::unique_ptr<GeometryNode>(new GeometryNode(std::unique_ptr<Plane>(new Plane(readNormal.x(), readNormal.y(), 
                                                                                                         readNormal.z(), readDistance)))));
  }*/

  std::unique_ptr<Curve> pCurve(new Curve(true));
  pCurve->addPoint(Point<float>(-100, -100, 0));
  pCurve->addPoint(Point<float>(100, -100, 0));
  pCurve->addPoint(Point<float>(100, 100, 0));
  pCurve->addPoint(Point<float>(-100, 100, 0));
  m_pCurve = pCurve.get();

  std::unique_ptr<CameraNode> pCameraNode(new CameraNode()); 
  pView1 ->setCameraNode(pCameraNode.get());
  ISceneNode* pCamNode = pView1->addSceneNode(std::move(pCameraNode));
  pView1->addSceneNode(std::unique_ptr<GeometryNode>(new GeometryNode(std::move(pCurve))));
  m_viewportManager.addViewport(std::move(pView1));
}

void AveragingController::onIdle()
{
  static int numTimes = 0;
  if (numTimes++ < 10)
  {
    m_pCurve->refine();
    m_pCurve->tuck(0.5);
    //m_pCurve->untuck(0.2);
    Fl::redraw();
  }
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
