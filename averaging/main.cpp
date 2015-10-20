#include "precomp.h"
#include "ViewportManager.h"
#include "averagingController.h"

int main(int argc, char* argv[])
{
  ViewportManager viewportManager(Rect<int>(0, 0, 1600, 1000));
  viewportManager.setAppController(std::unique_ptr<AveragingController>(new AveragingController(viewportManager)));

  return Fl::run();
}