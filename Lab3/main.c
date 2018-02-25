
# include "functions.c"
# include "functions.h"
# include "testStack.c"
# include "testStack.h"

int main(void) {
  // testPush();
  // testisEmpty();
  // testPop();
  Desk desk = makeDesk(3);
  displayDesk(&desk);

}
