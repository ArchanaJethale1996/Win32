TCHAR cpu_name[2][10] = {TEXT("Intel"),TEXT("AMD")};
TCHAR amd_generation[3][5] = { TEXT("A4"),TEXT("AM3"),TEXT("FX") };
TCHAR intel_generation[3][10] = { TEXT("Intel i3"),TEXT("Intel i5"),TEXT("Intel i7") };
TCHAR i3_architecture[6][12] = { TEXT("Westmere"),TEXT("Sandybridge"),TEXT("Haswell"),TEXT("Ivy"),TEXT("Skylake"),TEXT("Kaby Lake") };
TCHAR i3_architecture_price[6][5] = { TEXT("5989") ,TEXT("2000"),TEXT("1232"),TEXT("2233"),TEXT("1122"),TEXT("2212") };
TCHAR i5_architecture_price[6][5] = { TEXT("2231") ,TEXT("1221"),TEXT("6434"),TEXT("5565"),TEXT("5333"),TEXT("3555") };
TCHAR i7_architecture_price[6][5] = { TEXT("3342") ,TEXT("2344"),TEXT("4233"),TEXT("5989"),TEXT("5553"),TEXT("2344") };

TCHAR a4_architecture[6][12] = { TEXT("Hammer"),TEXT("K10"),TEXT("Bobcat"),TEXT("Bulldozer"),TEXT("Jaguar"),TEXT("Zen") };
TCHAR a4_architecture_price[6][5] = { TEXT("1243") ,TEXT("5559"),TEXT("4449"),TEXT("2389"),TEXT("9389"),TEXT("3322") };
TCHAR am3_architecture_price[6][5] = { TEXT("2433") ,TEXT("3423"),TEXT("2333"),TEXT("3332"),TEXT("5344"),TEXT("2344") };
TCHAR fx_architecture_price[6][5] = { TEXT("3455") ,TEXT("4432"),TEXT("3342"),TEXT("5959"),TEXT("5909"),TEXT("4489") };

TCHAR ram_company[3][12] = { TEXT("Gskill"),TEXT("Samsung"),TEXT("Transcend")};
TCHAR gskill_size[3][5] = { TEXT("4GB") ,TEXT("8GB"),TEXT("16GB")};
TCHAR gskill_price[3][6] = { TEXT("3499") ,TEXT("9999"),TEXT("15999") };

TCHAR samsung_size[4][5] = { TEXT("1GB") ,TEXT("2GB"),TEXT("4GB") ,TEXT("8GB") };
TCHAR samsumg_price[4][6] = { TEXT("720") ,TEXT("1320"),TEXT("3240"),TEXT("6500") };

TCHAR transcend_size[3][5] = { TEXT("1GB") ,TEXT("2GB"),TEXT("4GB") };
TCHAR transcend_price[3][6] = { TEXT("799") ,TEXT("1500"),TEXT("2690")};


TCHAR mother_company[3][10] = { TEXT("Asus"),TEXT("GigaByte"),TEXT("Zebronics") };
TCHAR mother_type[3][20] = { TEXT("7th Generation"),TEXT("8th Generation")};
TCHAR mother_price1[3][10] = { TEXT("3444"),TEXT("3233"),TEXT("2333") };
TCHAR mother_price2[3][10] = { TEXT("2362"),TEXT("2232"),TEXT("3344") };



TCHAR graphics_company[2][10] = { TEXT("NVIDIA"),TEXT("AMD")};
TCHAR nvidia_size[3][5] = { TEXT("2GB") ,TEXT("4GB"),TEXT("8GB") };
TCHAR nvidia_type[2][5] = { TEXT("DDR3") ,TEXT("DDR5")};
TCHAR nvidia_ddr3_price[3][5] = { TEXT("3260") ,TEXT("3456"),TEXT("3996") };
TCHAR nvidia_ddr5_price[3][7] = { TEXT("5649") ,TEXT("14100"),TEXT("55999") }; 

TCHAR amd_size[2][5] = { TEXT("1GB") ,TEXT("2GB") };
TCHAR amd_type[2][5] = { TEXT("DDR3") ,TEXT("DDR5") };
TCHAR amd_ddr3_price[2][5] = { TEXT("2799") ,TEXT("5999") };
TCHAR amd_ddr5_price[2][7] = { TEXT("5640") ,TEXT("10999") };

TCHAR harddisk_company[2][10] = { TEXT("Seagate"),TEXT("Toshiba") };
TCHAR sea_size[4][5] = { TEXT("1TB") ,TEXT("2TB"),TEXT("3TB"),TEXT("4TB") };
TCHAR sea_price[4][6] = { TEXT("3999") ,TEXT("5495"),TEXT("8700"),TEXT("10290") };

TCHAR to_size[4][5] = { TEXT("1TB") ,TEXT("2TB") };
TCHAR to_price[4][6] = { TEXT("4015") ,TEXT("4650")};

TCHAR key_company[3][10] = { TEXT("IBall"),TEXT("Dell"),TEXT("HP") };
TCHAR key_type[2][10] = {TEXT("Wired"),TEXT("Wireless")};
TCHAR key_price_w[3][5] = { TEXT("1499") ,TEXT("1399"),TEXT("1521") };
TCHAR key_price_wl[3][5] = { TEXT("2499") ,TEXT("2399"),TEXT("2521") };

TCHAR mouse_company[2][10] = { TEXT("Logitech"),TEXT("Dell") };
TCHAR mouse_type[2][10] = { TEXT("Wired"),TEXT("Wireless") };
TCHAR mouse_price_w[2][5] = { TEXT("549") ,TEXT("670") };
TCHAR mouse_price_wl[2][5] = { TEXT("749") ,TEXT("770") };

TCHAR cd_company[2][5] = { TEXT("Dell"),TEXT("LG") };
TCHAR cd_type[3][20] = { TEXT("Blu-ray Burner"),TEXT("Combo Drive"),TEXT("DVD-ROM") };
TCHAR cd_price1[2][5] = { TEXT("6444"),TEXT("6233")};
TCHAR cd_price2[2][5] = { TEXT("6362"),TEXT("6232")};
TCHAR cd_price3[2][5] = { TEXT("6500") ,TEXT("6999")};

TCHAR smps_company[2][10] = { TEXT("Zebronics"),TEXT("IBall") };
TCHAR smps_powerout[2][10] = {TEXT("Below 500") ,TEXT("500-749W")};
TCHAR smps_color[2][10] = { TEXT("Black"),TEXT("Gray") };
TCHAR smps_price11[2][5] = { TEXT("780") ,TEXT("1500") };
TCHAR smps_price12[2][5] = { TEXT("710") ,TEXT("2500") };
TCHAR smps_price21[2][5] = { TEXT("740") ,TEXT("2500") };
TCHAR smps_price22[2][5] = { TEXT("750") ,TEXT("1500") };


TCHAR cabinet_company[4][10] = { TEXT("BBC"),TEXT("Jonsbo"),TEXT("MiniITX"),TEXT("Intex") };
TCHAR cab_type[2][10] = { TEXT("Black"),TEXT("White")};
TCHAR cabinet_2_price[4][10] = { TEXT("1200"),TEXT("10228"),TEXT("3500"),TEXT("935") };
TCHAR cabinet_4_price[4][10] = { TEXT("2200"),TEXT("20228"),TEXT("22500"),TEXT("2235") };

TCHAR monitor_company[3][8] = { TEXT("Lenovo") ,TEXT("Dell"),TEXT("Samsung") };
TCHAR monitor_size[3][18] = { TEXT("15.4 inch") ,TEXT("18.4 inch") };
TCHAR monitor_type[3][18] = { TEXT("LED") ,TEXT("Curved"),TEXT("LCD") };
TCHAR monitor_price11[3][6] = { TEXT("3299") ,TEXT("2399"),TEXT("1899") };
TCHAR monitor_price12[3][6] = { TEXT("3499") ,TEXT("5929"),TEXT("1859") };
TCHAR monitor_price21[3][6] = { TEXT("2299") ,TEXT("5399"),TEXT("5899") };
TCHAR monitor_price22[3][6] = { TEXT("4499") ,TEXT("3929"),TEXT("4809") };
TCHAR monitor_price31[3][6] = { TEXT("5299") ,TEXT("5399"),TEXT("3899") };
TCHAR monitor_price32[3][6] = { TEXT("3499") ,TEXT("4929"),TEXT("5809") };

TCHAR pen_company[3][8] = { TEXT("Lenovo") ,TEXT("Dell"),TEXT("Samsung") };
TCHAR pen_size[3][5] = { TEXT("2GB") ,TEXT("4GB"),TEXT("8GB") };
TCHAR pen_2_price[3][6] = { TEXT("324") ,TEXT("239"),TEXT("199") };
TCHAR pen_4_price[3][6] = { TEXT("314") ,TEXT("229"),TEXT("699") };
TCHAR pen_8_price[3][6] = { TEXT("824") ,TEXT("839"),TEXT("899") };