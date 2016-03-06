# HimesP12Init
# Programmer: Alan Himes
# EMail: ahimes1@cnm.edu
# Purpose: points in a database

import sqlite3
conn = sqlite3.connect('pointsDB.db')
curs = conn.cursor()
curs.execute('''
CREATE TABLE geoPointDB(
    X INT,
    Y INT,
    Z INT,
    Desc TEXT
)
''')

startingData = (
    (100,200,123,'Main Campus'),
    (120,133,142,'Montoya'),
    (153,123,322,'Rio Rancho'),
    (133,123,143,'STEMULUS Center'),
    (153,142,122,'ATC')
    )

for row in startingData:
    sqlCmd = '''
        INSERT INTO geoPointDB (X, Y, Z, Desc)
        VALUES (%s, %s, %s,'%s')
        ''' % row
    curs.execute(sqlCmd)

conn.commit()
conn.close()

print 'pointsDB.db initialized!'
