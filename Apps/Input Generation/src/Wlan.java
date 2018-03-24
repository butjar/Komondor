
import java.awt.Point;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Sergio Barrachina-Munoz (sergio.barrachina@upf.edu)
 */
public class Wlan {

    public int wlan_id;		// WLAN ID
    public String wlan_code;	// Code of the WLAN (string)
    public int num_stas;	// Number of STAs in the WLAN (AP not included)
    public String ap_code;	// Id of the Access Point
    String[] list_sta_code;     // List of STAs IDs belonging to the WLAN
    int primary_channel;
    int min_ch_allowed;
    int max_ch_allowed;
    boolean wlan_80211ax;   // Legacy or IEEE 802.11 ax
    int channel_bonding_model;
    double traffic_load;
    Point[] stas_position_list;

    double x;
    double y;
    double z;

    public Wlan(){};
    public Wlan(int wlan_id, String wlan_code, int num_stas, String ap_code,
            String[] list_sta_code, int primary_channel, int min_ch_allowed,
            int max_ch_allowed, boolean wlan_80211ax, double x, double y, 
            double z, int channel_bonding_model, double traffic_load) {

        this.wlan_id = wlan_id;
        this.wlan_code = wlan_code;
        this.num_stas = num_stas;
        this.ap_code = ap_code;
        this.list_sta_code = list_sta_code;
        this.primary_channel = primary_channel;
        this.min_ch_allowed = min_ch_allowed;
        this.max_ch_allowed = max_ch_allowed;
        this.wlan_80211ax = wlan_80211ax;
        if(!this.wlan_80211ax){
            this.channel_bonding_model = 0; // SCB
        } else {
            this.channel_bonding_model = channel_bonding_model;
        }
        this.traffic_load = traffic_load;
        this.x = x;
        this.y = y;
        this.z = z;
    }
    
    public void set_stas_positions(Point[] stas_position_list){
        this.stas_position_list = stas_position_list;
    }

}
