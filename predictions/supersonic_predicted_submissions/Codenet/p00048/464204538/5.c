main(f) {
  for (; ~scanf("%f", &f);)
    puts(f > 91
             ? "heavy"
             : f > 81
                   ? "light heavy"
                   : f > 75
                         ? "middle"
                         : f > 69
                               ? "light middle"
                               : f > 64
                                     ? "welter"
                                     : f > 60
                                           ? "light welter"
                                           : f > 57
                                                 ? "light"
                                                 : f > 54
                                                       ? "feather"
                                                       : f > 51
                                                             ? "bantam"
                                                             : f > 48 ? "fly"
                                                                      : "light "
                                                                        "fly");
  return 0;
}
