/** 
 * Orinoco beacon structure
 * @author Christian Renner  (christian.renner@tuhh.de)
 * @author Andreas Reinhardt (andreasr@cse.unsw.edu.au)
 */
#ifndef ORINOCO_BEACON_MSG_H
#define ORINOCO_BEACON_MSG_H

typedef enum {
  ORINOCO_BEACON_FLAGS_ACCEPTSDATA  = 0x01
} orinoco_beacon_flags_t;

typedef enum {
  BLOOM_BYTES = 8,             // bytes in the Bloom filter (x8 for bits)
  BLOOM_HASHES = 3,            // number of hashes to calculate per entry
  BLOOM_VERSION_MAX = 0xFFF0,  // maximum version number of filter
  SHORT_BEACON = 0x80,         // packet carries a Bloom filter (0x00) or not (0x80)
} orinoco_routing_parameters_t;

typedef struct {
  uint8_t          hashes[BLOOM_HASHES]; // Offsets for each hash of local ID
  // IMPORTANT:    Increase this to uint16_t when BLOOM_BYTES >= 32
} orinoco_bloom_pointers_t;

typedef nx_struct {
  nx_uint8_t       cmd;                 // The command to execute at destinations
  nx_uint16_t      version;             // version number of Bloom filter
  nx_uint8_t       bloom[BLOOM_BYTES];  // Bloom filter of recipient IDs
} orinoco_routing_t;

typedef nx_struct OrinocoBeaconMsg {
  nx_uint8_t             seqno;
  nx_orinoco_pathcost_t  cost;      // Orinoco path metric offer
  nx_uint8_t             cw;        // congestion window
  nx_uint8_t             flags;     // status bits (see orinoco_beacon_flags_t)
  orinoco_routing_t      route;     // Support for down-tree routing
} OrinocoBeaconMsg;

#endif 

