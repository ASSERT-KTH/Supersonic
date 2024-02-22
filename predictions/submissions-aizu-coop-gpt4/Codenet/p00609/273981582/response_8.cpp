// The rest of the code remains the same...

// Replace set with unordered_set
unordered_set<Point> open[2];

// Use fast I/O
int readInt() {
    int number = 0;
    bool negative = false;
    int c = getchar_unlocked();
    if (c=='-') {
        negative = true;
        c = getchar_unlocked();
    }
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
    return number;
}

void writeInt(int n){
    if(n<0){
        n=-n;
        putchar_unlocked('-');
    }
    char buf[10];
    buf[9]='\0';
    int i=8;
    while(n){
        buf[i--]=n%10+'0';
        n/=10;
    }
    while(buf[++i]!='\0')
        putchar_unlocked(buf[i]);
}

// Replace scanf with readInt and printf with writeInt
while (an = readInt(), bn = readInt(), r = readInt(), an | bn) {
    // The rest of the code remains the same...
    writeInt(ans);
    putchar_unlocked('\n');
}