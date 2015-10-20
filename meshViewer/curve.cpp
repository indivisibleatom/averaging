#include "precomp.h"
#include "curve.h"

const float k_RadiusBalls = 10.0f;

Curve::Curve(bool fClosed) : m_fClosed(fClosed)
{
}

Curve::Curve(const Curve& other)
{
  m_points = other.m_points;
}

Curve& Curve::operator=(const Curve& other)
{
  Curve temp(other);
  temp.swap(*this);
  return *this;
}

void Curve::swap(Curve& other)
{
  std::swap(m_points, other.m_points);
}

int Curve::nv() const throw()
{
  return m_points.size();
}

void Curve::addPoint(const Point<float>& point)
{
  m_points.push_back(point);
}

void Curve::setPoint(int index, const Point<float>& point)
{
  assert(index < m_points.size() && index >= 0);
  m_points[index] = point;
}

void Curve::draw()
{
  if (m_fDrawDiscs)
  {
    for(const auto& point : m_points)
    {
      drawSphere(point, k_RadiusBalls, COLORS::BLACK, &QuadricWrapper());
    }
  }

  glBegin(GL_LINES);
  for (const auto& point : m_points)
  {
    glVertex3f(point.x(), point.y(), point.z());
  }
  
  if (m_fClosed) // Then close the curve
  {
    glVertex3f(m_points[0].x(), m_points[0].y(), m_points[0].z());
  }
  glEnd();
}

int Curve::onMousePressed(int mouseX, int mouseY, const IKeyboardState& keyboardState) { return 0; }
int Curve::onMouseReleased(int mouseX, int mouseY, const IKeyboardState& keyboardState){ return 0; }
int Curve::onMouseDragged(int mouseX, int mouseY, const IKeyboardState& keyboardState) { return 0; }
int Curve::onMouseMoved(int deltaX, int deltaY, const IKeyboardState& keyboardState) { return 0; }
int Curve::onClick(int mouseX, int mouseY, const IKeyboardState& keyboardState) { return 0; }
int Curve::onKeyReleased(int ch) { return 0; }

