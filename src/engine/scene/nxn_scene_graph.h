// nxn_scene_graph.h

#include "dynamic_array.h"
#include "icollider.h"
#include "itickable.h"

namespace StevensDev
{

namespace sgds
{

class NxNSceneGraph : public ITickable
{
  private:

  public:
      NxNSceneGraph( float dimensions, int divisions );
      void addCollider( ICollider* collider );
      void removeCollider( ICollider* collider );
      DynamicArray<ICollider*> find( float x, float y, float width,
              float height );
      DynamicArray<ICollider*> find( float x, float y, float width,
              float height, unsigned short flags );
      DynamicArray<ICollider*> find( const RectangleBounds& bounds );
      DynamicArray<ICollider*> find( const RectangleBounds& bounds,
              unsigned short flags );
      DynamicArray<ICollider*> find( const ICollider* collider );
};

} // End sgds namespace.

} // End StevensDev.
