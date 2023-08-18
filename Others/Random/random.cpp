//gen a random long long ; cout<<gen()

// int
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

// long long
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

// gen a random number from l to r; cout<<Rand(l,r);
    
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r);
    return rnd(gen);
}

srand(time(NULL));
rand() % (max - min + 1) + min;