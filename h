def regression():
    win = graphics.GraphWin("Regression Line Example", 300, 330)
    win.setCoords(-10,-12,10,10)
    descr = graphics.Text(graphics.Point(0,0), "This program calculates and draws n" + "the regression line for a sequence n"+  "of points in the plane. ")

    bot_text = graphics.Text(graphics.Point(0,-11), "Click anywhere to continue. ")
    descr.setSize(8)
    bot_text.setSize(8)
    descr.draw(win)
    bot_text.draw(win)
    win.getMouse()
    descr.undraw()

    bot_text.setText("Click on the graph to add points.")
    x_axis = graphics.Line(graphics.Point(-10,0), graphics.Point(10,0))
    x_axis.setArrow("last")
    y_axis = graphics.Line(graphics.Point(0,-10), graphics.Point(0,10))
    y_axis.setArrow("last")
    y_axis.draw(win)
    x_axis.draw(win)
    done = graphics.Rectangle(graphics.Point(-9.5, -11.5), graphics.Point(-6, -10.5))
    done.setFill("grey")
    done_text = graphics.Text(graphics.Point(-7.75, -11), "Done")
    done_text.setSize(10)
    done.draw(win)
    done_text.draw(win)
    x_coords = []
    y_coords = []
    click = win.getMouse()
    while not (-9.5 <= click.getX() <= -6 and -11.5 <= click.getY() <= 10.5):
        click.draw(win)
        x_coords.append(click.getX())
        y_coords.append(click.getY())
        click = win.getMouse()

    n = len(x_coords)
    if n > 0:
        x_bar = sum(x_coords)/n
        y_bar = sum(y_coords)/n
        numerator = -n * x_bar * y_bar
        denominator = -n * x_bar **2
        for i in range(n):
            numerator += x_coords [i] * y_coords [i]
            denominator += x_coords[i] **2
        m = numerator/denominator
        left_y = y_bar + m*(-10 - x_bar)
        right_y = y_bar + m * (10 - x_bar)
    bot_text.undraw()
    done.undraw()
    done_text.undraw()
    if n>0 :

        reg_line = graphics.Line(graphics.Point(-10, left_y), graphics.Point(10,right_y))
        reg_line.setOutline("red")
        reg_line.draw(win)


    win.getMouse()
    win.close()
