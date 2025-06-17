    #include <iostream>
    #include <vector>

    using namespace std;

    int main(void)
    {
        freopen("ACMHotel.txt", "r", stdin);
        int T;

        cin >> T;

        for (int i = 0; i < T; i++)
        {
            int H, W, N;

            cin >> H >> W >> N;

            int floor = N % H;
            int num = N / H;

            if (floor == 0)
            {
                floor = H;
            }
            else
            {
                num++;
            }

            if (num >= 10)
            {
                cout << floor << num << endl;
            }
            else
            {
                cout << floor << "0" << num << endl;
            }
        }

        return 0;
    }