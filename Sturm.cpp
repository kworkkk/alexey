#include "division_rosetta.cpp"


vector<double> derivative(vector<double> P){
    vector<double> dP;
    double new_term;
    int i = P.size() - 1;
    for(double term: P) {
        dP.push_back(term * i);
        i--;
    }
    return dP;
}


int get_degree(vector<double> P){
    int i = P.size() - 1;
    while(P[i] == 0) {

        i--;
    }

    return i;
}


double unary_minus_for_items(double item){
    return -item;
}


int unary_minus(vector<double> &V){
    transform(
        V.begin(),
        V.end(),
        V.begin(),
        [](double &item){return -item;}
    );
    return 0;
}


/*
void divide_polynom_A_by_polynom_B(A, B){

}
*/


vector <
    pair<
        vector <double>,
        int
    > 
> construct_Sturm_chain(vector<double> P, int degree) {
    vector <
        pair<
            vector <double>,
            int
        > 
    > Sturm_chain;
    pair<vector<double>, int>  remainder;
    vector<double> zero_vector(P.size());


    Sturm_chain.push_back(
        pair<vector<double>, int>{P, degree}
    );
    Sturm_chain.push_back(
        pair<vector<double>, int>{derivative(P), degree - 1}
    );

    double i = 1;
    while(
        Sturm_chain.back().second != 0 &&
        i < P.size() + 3    // for dev purposes to avoid endless while
    ) {
        remainder = divide_polynom_A_by_polynom_B(
            Sturm_chain.rbegin()[1].first, 
            Sturm_chain.rbegin()[0].first,
            Sturm_chain.rbegin()[1].second,
            Sturm_chain.rbegin()[0].second
        ).second;
        unary_minus(remainder.first);
        Sturm_chain.push_back( remainder );
        i++;
    }
    
    return Sturm_chain;
}

