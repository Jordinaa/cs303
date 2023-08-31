

vector<vector<vector<int>>> readMatrixFile(string filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: File not found" << endl;
        exit(1);
    }
    vector<vector<vector<int>>> matrices;
    string line;
    while (getline(infile, line)) {
        istringstream iss(line);

        // read the first integer to get the matrix size
        int n;
        iss >> n;
        // create a matrix of size n x n
        vector<vector<int>> matrix(n, vector<int>(n));
        // read the rest of the line and populate the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!(iss >> matrix[i][j])) {
                    cerr << "not enough elements in the line for matrix of size " << n << endl;
                    exit(1);
                }
            }
        }
        matrices.push_back(matrix);
    }

    return matrices;
}