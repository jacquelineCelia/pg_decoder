function save_raw_pca_whitened(X, counter, filename, dim);

list = importdata(filename, '\n');

index = 0;

for i = 1:size(list);
    list{i}
    fid = fopen(list{i}, 'w');
    frame_number = counter(i)/dim;
    data = X(index + 1 : index + frame_number, :)';
    size(data)
    index = index + frame_number
    fwrite(fid, data, 'float32');
    fclose(fid);
end
    
