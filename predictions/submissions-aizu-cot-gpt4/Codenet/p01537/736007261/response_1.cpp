The provided code is quite complex and involves many mathematical computations. The majority of the functions use complex numbers, which is computationally heavy. The code also contains a lot of repetitive tasks that can be optimized.

Here are some of the steps that can help to optimize this code:

1. The preprocessor directives at the beginning of the code include some unnecessary libraries which can be removed like cmath, ctime, sstream, utility, etc.

2. The code has used the complex data type that is heavy and slows down the execution. If possible, try to use primitive data types.

3. The code contains a lot of repetitive tasks. For instance, the distance between points is computed multiple times throughout the code. You can consider storing these values the first time they're computed and then reusing them as and when needed.

4. The code also contains a lot of unnecessary type conversions which can be avoided.

5. The code uses unnecessary global variables which can be avoided.

The optimized code for the above program is hard to provide without knowing the exact functionality and requirements of the program. The above points can be considered to start the optimization process. 

I would recommend refactoring this code in a way that it becomes more modular and easier to understand. The current structure is quite complex and not easy to optimize without risking breaking the functionality. 
