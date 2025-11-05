class Human:
    def __init__(self, name, prevLabs, submittingLabs, attended, current):
        try:
            if(not name and not name.strip()):
                raise Exception(f"\033[31mError in Human.__init__(). Empty name!\033[0m")
            self.name = name.capitalize().split(maxsplit=1)[0]
            self.prevLabs = int(prevLabs)
            self.submittingLabs = int(submittingLabs)
            if prevLabs >= submittingLabs:
                raise Exception(f"\033[31mError in Human.__init__(). PrevLabs cannot be greater than submittingLabs. Problem with {name}\033[0m")
            self.attended = 0
            if(attended.lower() == "да"):
                self.attended = 10
            self.current = current
            self.total = None
        except Exception as ex:
            raise Exception(f"\033[31mError in Human.__init__(). Invalid data in table! {ex}\033[0m")

    def getScore(self):
        if(self.total != None):
            raise Exception("\033[31mError in Human.getScore(). Total score is not empty!\033[0m")
        try:
            self.total = int(self.prevLabs) + int(self.submittingLabs) + self.attended
        except Exception as ex:
            raise Exception("\033[31mError in Human.getScore(). Error while getting total score: " + str(ex) + "\033[0m")

        if(self.submittingLabs == self.current):
            self.total -= 11

        if(self.name == "Мышковец" or self.name == "Макаревич"):
            self.total -= 2

        return self.total

    def getHumanCSVRow(self):
        if(self.total == None):
            raise Exception("\033[31mError in Human.getHumanCSVRow(). Total score is empty!\033[0m")
        return [
            self.name,
            self.prevLabs,
            self.submittingLabs,
            "Да" if self.attended == 10 else "Нет",
            self.current,
            self.total
        ]

    def getHumanStr(self):
        if (self.total == None):
            raise Exception("\033[31mError in Human.getHumanCSVRow(). Total score is empty!\033[0m")
        someStr = self.name + " " + str(self.prevLabs) + " " + str(self.submittingLabs) + " " + "Да " if self.attended == 10 else "Нет "
        someStr += str(self.current) + " " + str(self.total)
        return someStr