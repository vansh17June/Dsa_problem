SELECT 
    R.contest_id,
    ROUND(
        COUNT(R.user_id) * 100 / (SELECT COUNT(*) FROM Users),
        2
    ) AS percentage
FROM Register AS R
LEFT JOIN Users AS U
    ON U.user_id = R.user_id
GROUP BY R.contest_id
ORDER BY percentage DESC, R.contest_id ASC;