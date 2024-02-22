vector<int> y_conversion(2 * m_t + 1);
for (int y = -m_t; y <= m_t; y++) {
  y_conversion[y + m_t] = y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
}