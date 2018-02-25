// # include "functions.h"
// # include "testStack.h"
//
// void testisEmpty() {
//   Node *stack = makeNode(0.0);
//   if (isEmpty(stack))
//     printf("It's empty! \n");
//   else
//     printf("It's not empty! \n");
//   pop(&stack);
//   if (isEmpty(stack))
//     printf("It's empty! \n");
//   else
//     printf("It's not empty! \n");
//
// }
//
// void testPop() {
//   Node *stack = makeNode(0.0);
//   printf("The top is %.2f\n", top(stack));
//   push(&stack, 1.0);
//   printf("The top is %.2f\n", top(stack));
//
// }
//
// void testPush() {
//   Node *stack = makeNode(0.0);
//   printf("pushing...\n");
//   push(&stack, 1.0);
//   push(&stack, 2.0);
//   push(&stack, 3.0);
//   push(&stack, 4.0);
//   push(&stack, 5.0);
//   push(&stack, 6.0);
//   pop(&stack);
//   pop(&stack);
//   pop(&stack);
//   pop(&stack);
//   pop(&stack);
//   pop(&stack);
// }
