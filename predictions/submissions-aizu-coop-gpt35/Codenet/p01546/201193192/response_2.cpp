// Before
memset(dp, -1, sizeof(dp));
memset(prv, -1, sizeof(prv));

// After
std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), -1);
std::fill(&prv[0][0], &prv[0][0] + sizeof(prv) / sizeof(prv[0][0]), -1);