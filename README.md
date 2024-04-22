# FuelSaver-Managing-Vehicle-Efficiency-for-Emissions-Reduction
Brand - un șir de caractere ce reprezintă marca mașinii;
Numărul de inmatriculare - un șir de caractere ce reprezintă numărul de înmatriculare;
Anul fabricației - un număr natural ce reprezintă anul fabricației;
Consum mediu - un număr rațional, in simplă precizie, ce reprezintă consumul mediu al mașinii;
Numărul de km - numărul de kilometri parcurs de acea mașină;
Pentru fiecare tip de mașină se poate calcula consumul, astfel:

Benzină - (0.879 * consumul_mediu * numar_kilometri) / 100;
Motorină - (0.789 * consumul_mediu * numar_kilometri) / 100;
Hibrid - (consumul_mediu * numar_kilometri - 0.124 * numar_kilometri) / 100
Electrica - 0
