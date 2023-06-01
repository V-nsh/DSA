class UndergroundSystem(object):

    def __init__(self):
        self.checkins = {}
        self.trips = {}

    def checkIn(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        self.checkins[id] = [stationName, t]
        

    def checkOut(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        if id in self.checkins:
            startStation, startTime = self.checkins[id]
            del self.checkins[id]
            key = (startStation, stationName)
            if key not in self.trips:
                self.trips[key] = [0, 0] # [total time, total trips]
            self.trips[key][0] += t - startTime
            self.trips[key][1] += 1

    def getAverageTime(self, startStation, endStation):
        """
        :type startStation: str
        :type endStation: str
        :rtype: float
        """
        key = (startStation, endStation)
        if key in self.trips:
            return float(self.trips[key][0]) / self.trips[key][1]        


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)