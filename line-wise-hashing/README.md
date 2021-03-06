### Description ###

These programs make it convenient to find the line-wise md5, sha1 and sha256 hashes, e.g.:
```
seq 10 | ./md5
```

Output:

```none
c4ca4238a0b923820dcc509a6f75849b        1
c81e728d9d4c2f636f067f89cc14862c        2
eccbc87e4b5ce2fe28308fd9f2a7baf3        3
a87ff679a2f3e71d9181a67b7542122c        4
e4da3b7fbbce2345d7772b0674a318d5        5
1679091c5a880faf6fb5e6087eb1b2dc        6
8f14e45fceea167a5a36dedd4bea2543        7
c9f0f895fb98ab9159f51fd0297e236d        8
45c48cce2e2d7fbdea1afc51c7c6ad26        9
d3d9446802a44259755d38e6d163e820        10
```

The equivalent md5sum(1) would be:
```
seq 10 | 
while read; do 
  printf "%s" "$REPLY" | md5sum 
done
```

### Compile ###

```
make
```

### Another alternative ###

An fairly efficient alternative is to use perl, e.g.:
```
seq 10 | perl -MDigest::MD5=md5_hex    -lpe '$_=md5_hex   ($_) . "\t" . $_'
seq 10 | perl -MDigest::SHA=sha1_hex   -lpe '$_=sha1_hex  ($_) . "\t" . $_'
seq 10 | perl -MDigest::SHA=sha256_hex -lpe '$_=sha256_hex($_) . "\t" . $_'
```
etc.
