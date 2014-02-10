function do_pca_whitening(filein, dim);

[X, counter] = load_raw_mfcc(filein, dim);
mean(X)
var(X)
