function [X, counter] = load_raw_mfcc(filename, dim);

list = importdata(filename, '\n');

counter = [];
data = [];

for i = 1 : size(list);
    i
    list{i}
    fid = fopen(list{i});
    [A count] = fread(fid, '*float');
    counter = [counter count];
    data = [data; A];
    fclose(fid);
end;

X = reshape(data, dim, sum(counter)/dim)';
