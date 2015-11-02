// rectangle_bounds.h

namespace StevensDev
{

namespace sgds
{

class RectangleBounds
{
  private:
      float d_x;
      float d_y;
  public:
      float x() const;
      float y() const;
      float width() const;
      float height() const;
      void setX( float x );
      void setY( float y );
      void setWidth( float width );
      void setHeight( float height );
      void setDimensions( float width, float height );
      void setPosition( float x, float y );
      bool doesCollide( const RectangleBounds& candidate );
};

} // End sgds namespace.

} // End StevensDev namespace.
