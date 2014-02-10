function [avg, var] = do_pca_whitening(filein, fileout, dim, fout);

[X, counter] = load_raw_mfcc(filein, dim);
avg = mean(X);

[coeff, scores, latent] = get_pca(X, counter);

save(fout, 'coeff', 'latent', 'avg', '-v7.3');

%X = whitening(scores, latent); 

%save_raw_pca_whitened(X, counter, fileout, dim);
