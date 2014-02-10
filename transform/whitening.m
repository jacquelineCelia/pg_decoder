function X = whitening(scores, latent); 

scale = diag(1./sqrt(latent));
X = scores * scale;