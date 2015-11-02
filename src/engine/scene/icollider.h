// icollider.h

#include "rectangle_bounds.h"

namespace StevensDev
{

namespace sgds
{

class ICollider
{
  private:

  private:
      RectangleBounds& bounds();
      unsigned short flags() const;
      void setFlags( unsigned short flags );
      bool canCollide( unsigned short flags ) const;
      bool doesCollide( const RectangleBounds& candidate );
};

} // End sgds namespace.

} // End StevensDev namespace.
