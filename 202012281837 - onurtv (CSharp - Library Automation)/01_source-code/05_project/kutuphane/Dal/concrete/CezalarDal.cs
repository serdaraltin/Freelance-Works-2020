using Dal.Abstract;
using Dal.genericRepository.Concrete;
using entities.Concrete;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dal.concrete
{
    //cezalar deposuna ait soyut sınıfın tanımı
    public class CezalarDal:RepositoryBase<cezalar>,ICezalarDal
    {
    }
}
