main() {
  float f;
  for (; ~scanf("%f", &f);)
    puts(f > 91
            ? "heavy"
            : f > 81
             : f > 81
                   ? "middle heavy"
                      ? "middle"
                        : f > 69
                          ? "light middle"
                            ? "welter"
                             ? "welter"
                               ? "light welter"
                                    : f > 57
                                  ? "light welter"
                                   : f > 57
                                      ? "light"
                                 ? "light"
              