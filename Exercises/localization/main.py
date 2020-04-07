#Given the list motions=[1,1] which means the robot 
#moves right and then right again, compute the posterior 
#distribution if the robot first senses red, then moves 
#right one, then senses green, then moves right again, 
#starting with a uniform prior distribution.

p = [0.2, 0.2, 0.2, 0.2, 0.2]
world = ['green', 'red', 'red', 'green', 'green']
measurements = ['red', 'green']
motions = [1,1]
pHit = 0.6
pMiss = 0.2
pExact = 0.8
pOvershoot = 0.1
pUndershoot = 0.1

# based of measurments or observations of robot
def sense(p, Z):
    """
        p = starting p values - list 
        Z = measurement - string
    """    
    # store the new p values
    q=[]
    
    # updates the values of p with hit or miss values
    # hit:  .2 * .6
    # miss: .2 * .2
    for i in range(len(p)):
        # returns 1 or 0
        hit = (Z == world[i])
       
        # if hit is true it cancels the right half of statement
        # if hit is false is cancles out the left half
        q.append(p[i] * (hit * pHit + (1-hit) * pMiss))

    # get the normalizing sum
    s = sum(q)
    
    # normalize q values    
    for i in range(len(q)):
        q[i] = q[i] / s
    
    return q

# robot movement 
def move(p, U):
    """
        p is starting p values
        U is movement number
    """
    q = []
    
    for i in range(len(p)):        
        ## this is a modulos trick to shift index based on movement
        s = pExact * p[(i-U) % len(p)]
       
    # baked in overshoot and undershoot probabilities
        s = s + pOvershoot * p[(i-U-1) % len(p)]
        s = s + pUndershoot * p[(i-U+1) % len(p)]
        q.append(s)
    
   
    return q

# run code for any number of measurments
for m in range(len(measurements)):
    # change probabliities based on measurments of robot
    p = sense(p, measurements[m])
    # change probablities based on movements of robot
    p = move(p, motions[m])


print(p) 