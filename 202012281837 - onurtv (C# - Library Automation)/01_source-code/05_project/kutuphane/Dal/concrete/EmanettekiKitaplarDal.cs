using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Dal.Abstract;
using Dal.genericRepository.Concrete;
using entities.Concrete;
namespace Dal.concrete
{
    //emanetteki kitaplar deposuna ait soyut sınıfın tanımı
    public class EmanettekiKitaplarDal : RepositoryBase<emanettekiKitaplar>, IEmanettekiKitaplarDal
    {
        kutuphaneContext ctx = new kutuphaneContext();
        public List<emanettekiKitaplar> getAllByStudentId(int studentId)
        {
            return ctx.emanettekiKitaplar.Where(x => x.ogrenciID == studentId).OrderByDescending(x => x.teslimTarihi).ToList();
        }
    }
}
