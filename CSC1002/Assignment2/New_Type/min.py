import math
class Expr(str):
    def completion(self):
        expr = list(self+'\n')
        for i in range(len(expr) - 1):
            if (expr[i].isdigit() or expr[i] == ')') and expr[i + 1].isalpha():
                expr[i] += '*'
        return ''.join(expr)
    def get_coef(self):
        f = self.completion()
        x, y = (0, 0)
        const = eval(f)
        x, y = (1, 0)
        coefficient_x = eval(f) - const
        x, y = (0, 1)
        coefficient_y = eval(f) - const
        if coefficient_x == 0 and coefficient_y == 0:
            raise ValueError('Not a line.')
        return coefficient_x, coefficient_y, const
def calc_intersection(l1, l2):
    a1, b1, c1 = l1
    a2, b2, c2 = l2
    if b1 == 0:
        if b2 == 0:
            if c1 / a1 == c2 / a2:
                raise ValueError('Same line found.')
            else:
                raise ValueError('Parallel line found.')
        x = - c1 / a1
        return x, (-c2 - a2 * x) / b2
    elif b2 == 0:
        return calc_intersection(l2, l1)
    else:
        a1, b1, c1 = a1 / b1, 1, c1 / b1
        a2, b2, c2 = a2 / b2, 1, c2 / b2
        if a1 == 0 or a2 == 0:
            return_value = list(calc_intersection((b1, a1, c1), (b2, a2, c2)))
            return_value.reverse()
            return tuple(return_value)
        if a1 == a2:
            raise ValueError('Parallel line found.')
        else:
            x = (c1 - c2) / (a2 - a1)
            return x, (-c1 - a1 * x) / b1
def calc_side(p1, p2):
    area = math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)
    if area == 0:
        raise ValueError('No triangle is found. ')
    return area
def calc_area(side):
    p = (sum(side)) / 2
    return math.sqrt(p * (p - side[0]) * (p - side[1]) * (p - side[2]))
def input_t(*args, **kwargs):
    input_value = input(*args, **kwargs)
    if input_value == 'Terminate':
        exit()
    else:
        return input_value
while True:
    try:
        print('-------------------------\'Terminate\' to terminate------------------------------')
        line, intersection_point, side = [], [], []
        for i in range(3):
            line.append(Expr('('+')-('.join(input_t('The line{} is: '.format(i + 1)).split('='))+')').get_coef())
        for i in range(3):
            intersection_point.append(calc_intersection(line[i-1], line[i]))
        for i in range(3):
            side.append(calc_side(intersection_point[i-1], intersection_point[i]))
        print('\nThe size is {0:g}'.format(calc_area(side)))
    except Exception as e:
        print('\n[ERROR]:', e, 'Try again...')