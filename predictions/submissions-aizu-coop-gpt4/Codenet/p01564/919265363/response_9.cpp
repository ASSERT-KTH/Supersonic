void recalc() {
  Monoid left_reflect = left != nil ? left->reflect() : Monoid();
  Monoid right_reflect = right != nil ? right->reflect() : Monoid();
  
  sum = value;
  if (left != nil) {
    sum = left_reflect + sum;
    left->per = this;
  }
  if (right != nil) {
    sum = sum + right_reflect;
    right->per = this;
  }
}