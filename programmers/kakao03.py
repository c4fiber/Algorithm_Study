fees = [180, 5000, 10, 600]
records = ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]

def timeToIntegerMinute(time):
    h, m = [int(i) for i in time.split(':')]
    return h * 60 + m

def chargeOutCars(records, parkingLot, parkingTime):
    for record in records:
        time, car, status = record.split(' ')
        time = timeToIntegerMinute(time)

        if status == 'IN':
            parkingLot[car] = time
            if car not in parkingTime:
                parkingTime[car] = 0
        else:
            parkingTime[car] += time - parkingLot[car]
            del parkingLot[car]

def chargeNotOutCars(parkingLot, parkingTime):
    for car in parkingLot.keys():
        parkingTime[car] += (23*60+59) - parkingLot[car]

def calculateFees(fees, parkingTime):
    answer = []
    cars = list(parkingTime.keys())
    cars.sort()

    basicTime, basicFee, perTime, perFee = fees

    for car in cars:
        if parkingTime[car] <= basicTime:
            fee = basicFee
        else:
            fee = basicFee + ( (parkingTime[car] - basicTime - 1) // perTime + 1 ) * perFee
        answer.append(fee)
    return answer


def solution(fees, records):
    parkingLot = {}
    parkingTime = {}
    answer = []

    
    chargeOutCars(records, parkingLot, parkingTime)
    chargeNotOutCars(parkingLot, parkingTime)
    answer = calculateFees(fees, parkingTime)


    return answer



print(solution(fees, records))
