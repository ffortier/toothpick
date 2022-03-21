#include "sketch.h"
#include "toothpick.h"

int main()
{
  Sketch sketch;

  if (!sketch.init()) {
    return 1;
  }

  Toothpick* root = new Toothpick(400, 400, 1, &sketch);

  sketch.addToothpick(root);
  sketch.run();
  sketch.quit();

  return 0;
}
