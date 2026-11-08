#include <bits/stdc++.h>
using namespace std;

class Television {
private:
    int volume;
    int mode;
    int channel;
    static int tvCount;
    static int dvdCount;

public:
	Television() : volume(50), mode(1), channel(0) {
        tvCount++;
    }
    
    Television(int id) : volume(50), mode(1), channel(id) {
        tvCount++;
    }

	void setId(int id) {
        channel = id;
    }
    
    void print(int id) {
        string modeStr = (mode == 1) ? "TV模式" : "DVD模式";
        cout << "第" << id << "号电视机--" << modeStr << "--频道" << 
		channel << "--音量" << volume << endl;
    }

    void setMode(int newMode) {
        if (mode != newMode) {
            if (mode == 1) {
                tvCount--;
            } else {
                dvdCount--;
            }
            mode = newMode;

            if (mode == 1) {
                tvCount++;
            } else {
                dvdCount++;
            }
        }
    }

    void setChannel(int newChannel) {
        channel = newChannel;
    }

    void adjustVolume(int delta) {
        volume += delta;
        if (volume > 100) {
            volume = 100;
        } else if (volume < 0) {
            volume = 0;
        }
    }

    int getMode() {
        return mode;
    }

    int getChannel() {
        return channel;
    }

    static int getTVCount() {
        return tvCount;
    }

    static int getDVDCount() {
        return dvdCount;
    }

    friend void remoteControl(Television& tv, int newMode, int deltaVolume, int newChannel);
};

int Television::tvCount = 0;
int Television::dvdCount = 0;
 
void remoteControl(Television& tv, int newMode, int deltaVolume, int newChannel) {
    if (newMode == 2) {
        newChannel = 99;
    }

    tv.setMode(newMode);
    tv.setChannel(newChannel);
    tv.adjustVolume(deltaVolume);

}

int main() {
    int n, t;
    cin >> n >> t;

    Television* tvs = new Television[n + 1];
    
    for (int i = 1; i <= n; i++) {
        tvs[i].setId(i);
    }
    
    while (t--) {
        int id, mode, channel, deltaVolume;
        cin >> id >> mode >> channel >> deltaVolume;

        remoteControl(tvs[id], mode, deltaVolume, channel);

        tvs[id].print(id);
    }

    cout << "播放电视的电视机数量为" << Television::getTVCount() - 1 << endl;
    cout << "播放DVD的电视机数量为" << Television::getDVDCount() << endl;

    delete[] tvs;

}
