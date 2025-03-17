void BuscaProf(MATRIZ m[V][V], int i, Flag[]{
    Flag[i] = 1; //Descoberto
    
    for (int j = 1; j <= V; j++){
        if(m[i][j] == 1 && Flag[j] == 0) BuscaProf(m, j, Flag);
    }

    Flag[i] = 2;
}