zeros_list = [0] * 100

zeros_tuple = (0,) * 100

vector_list = [[1,2,3]]
for i, vector in enumerate(vector_list * 3):
    print("{0} scalar product of vector: {1}".format((i + 1), [(i + 1) * e for e in vector]))
